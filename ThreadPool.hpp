#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

class ThreadPool
{
  public:
	ThreadPool(uint8_t numThreads = std::thread::hardware_concurrency())
	{
		for (uint8_t i = 0; i < numThreads; i++)
		{
			threads.emplace_back([this] {
				while (true)
				{
					std::unique_lock<std::mutex> lock(queueMutex);
					condition.wait(lock, [this] { return !tasks.empty() || stop; });
					if (stop && tasks.empty())
					{
						return;
					}
					std::function<void()> task = std::move(tasks.front());
					tasks.pop();
					lock.unlock();
					task();
				}
			});
		}
	}

	void enque(std::function<void()> task)
	{
		std::unique_lock<std::mutex> lock(queueMutex);
		tasks.emplace(std::move(task));
		lock.unlock();
		condition.notify_one();
	}

	~ThreadPool()
	{
		std::unique_lock<std::mutex> lock(queueMutex);
		stop = true;
		condition.notify_all();
		lock.unlock();
		for (auto &thread : threads)
		{
			thread.join();
		}
	}

  private:
	std::vector<std::thread> threads;
	std::queue<std::function<void()>> tasks;
	std::mutex queueMutex;
	std::condition_variable condition;
	uint8_t numThreads;
	bool stop = false;
};