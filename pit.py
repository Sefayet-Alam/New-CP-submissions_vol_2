def throwTheBall(receiver, seconds):
  """
  Finds the friend who has the ball after k seconds.

  Args:
    receiver: An array of integers, where receiver[i] is the friend that the ith friend throws the ball to.
    seconds: The number of seconds that the game lasts.

  Returns:
    The friend who has the ball after k seconds.
  """

  # Initialize the current friend with the ball to be 1.
  current_friend = 1

  # Iterate for the number of seconds.
  for i in range(seconds):
    # Get the next friend to throw the ball to.
    next_friend = receiver[current_friend]

    # Update the current friend to be the next friend.
    current_friend = next_friend

  # Return the friend who has the ball after k seconds.
  return current_friend


def main():
  # Read the number of friends and the array of receivers from STDIN.
  n, receiver = [int(x) for x in input().split()]

  # Find the friend who has the ball after k seconds.
  friend_with_ball = throwTheBall(receiver, n)

  # Print the friend who has the ball after k seconds.
  print(friend_with_ball)


if __name__ == "__main__":
  main()
