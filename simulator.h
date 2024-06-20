#ifndef SIMULATOR_H
#define SIMULATOR_H

#define RANDOM_SEED 369369

#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>

class Simulator;

class Schedule {
private:
  double time_;
  std::function<void()> function_;

public:
  double time() { return time_; }
  void call() { function_(); }

  Schedule(double time, std::function<void()> function)
      : time_(time), function_(function) {}
};

struct Compare{
	bool operator()(Schedule& a, Schedule& b){
		// false를 반환하면 p1이 앞으로 나옴
		return a.time() > b.time();
	}
};

class Simulator {
private:
  static double time_;
  static std::priority_queue<Schedule, std::vector<Schedule>, Compare> scheduleQueue_;

public:
  static double now() { return time_; }

  static void prepare() { srand(RANDOM_SEED); }

  static void schedule(double time, std::function<void()> function) {
    // 스케줄 큐에 스케줄을 추가한다.
    Schedule schedule(time, function);
    scheduleQueue_.push(schedule);
  }

  static void run() {
    // 모든 스케줄을 실행한다.
    while(scheduleQueue_.size()>0){
      Schedule schedule=scheduleQueue_.top();
      scheduleQueue_.pop();
      time_=schedule.time();
      schedule.call();
    }
  }
};

#endif