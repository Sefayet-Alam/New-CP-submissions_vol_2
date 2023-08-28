import random
import time
import matplotlib.pyplot as plt

def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def generate_random_numbers(n):
    return [random.randint(1, 100) for _ in range(n)]

def plot_graph(x, y):
    plt.plot(x, y)
    plt.xlabel('Number of Elements')
    plt.ylabel('Time Taken (seconds)')
    plt.title('Selection Sort Performance')
    plt.show()

def main():
    num_experiments = 5
    elements = [100, 500, 1000, 5000, 10000]  # Different values of n

    for n in elements:
        total_time = 0
        for _ in range(num_experiments):
            numbers = generate_random_numbers(n)
            start_time = time.time()
            selection_sort(numbers)
            end_time = time.time()
            total_time += end_time - start_time
        average_time = total_time / num_experiments
        print(f"Number of elements: {n} \t Average Time: {average_time} seconds")

    plot_graph(elements, [average_time / num_experiments for _ in elements])

if __name__ == '__main__':
    main()
