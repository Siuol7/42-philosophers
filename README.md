# 🍝 Philosophers
*Threading symphony where thinkers meet spaghetti*

## 🎯 Overview
Solve the classic dining philosophers problem with threads and mutexes. Watch philosophers eat, think, and sleep around a circular table while sharing forks—without starving or deadlocking.

## 🌟 Core Features
🧠 **Philosopher lifecycle:** eat → sleep → think → repeat  
🍴 **Fork sharing:** each philosopher needs 2 forks to eat  
⏱️ **Precise timing:** millisecond-accurate sleep/eat durations  
🔒 **Mutex magic:** prevent data races and deadlocks  
💀 **Death detection:** monitor starvation in real-time  

## 🚀 Quick Start
```bash
git clone https://github.com/Siuol7/42-philosophers.git philosophers
```
```bash
cd philosophers
```
```bash
make
```

## 🎮 Usage
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]
```
## 🔍 Behind the Scenes
- **Thread per philosopher:** independent thinking and actions
- **Mutex per fork:** synchronized resource access  
- **Death monitor:** separate thread watching for starvation
- **Precise timing:** accurate microsecond delays

## 🏆 Bonus
**philo_bonus:** Process-based implementation using semaphores for ultimate isolation

## 🎓 Skills Mastered
- Thread synchronization & mutexes
- Deadlock prevention strategies  
- Race condition elimination
- Process timing & monitoring

---
*"No philosopher shall starve in the pursuit of knowledge"*
