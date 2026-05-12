# SwiftCare Hospital Queue System

A simple hospital emergency queue system built in C++ using a Max Heap data structure.  
Patients with higher priority are treated first.

---

## Features

- Add patients with priority
- Extract the highest-priority patient
- Print all patients in the heap
- Uses a custom Max Heap implementation
- Dynamic memory allocation
- Exception handling for empty heap

---

# Heap Formulas Used

## Parent Node

From any index i:

parent = (i - 1) / 2

## Left Child

left = 2*i + 1

## Right Child

right = 2*i + 2

---

# Project Structure

SwiftCare/
│
├── main.cpp
└── README.md

---

# How It Works

The system stores patients inside a Max Heap.

Each patient has:

```cpp
struct Patient{
    string name;
    int priority;
};
