// B Taylor
// Solving The Elementary Problems on https://adriann.github.io/programming_problems.html

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Task 1: Print "Hello World"
void helloWorld()
{
	cout << "Hello World";
}

// Tasks 2 and 3: Name input + greeting message if name is correct
void greeting()
{
	// I may have expanded on this a little for no particular reason. At least I learnt about cin.getline().

	string name, colour;
	char quest[256];

	cout << "What is your name?" << endl;
	cin >> name;

	cout << "What is your quest?" << endl;
	cin.ignore(); // needed to ignore the newline character at the end of the last cin
	cin.getline(quest, 256); // Apparently std::cin doesn't allow you to take an input with spaces so I had to use this :(

	cout << "What is your favourite colour?" << endl;
	cin >> colour;

	if (name == "Ben" or name == "Joe")
		cout << "Right then. Off you go, " << name << ". Go and try " << quest << " you beautiful " << colour << " bastard.";
	else
		cout << "I don't know you >:(";
}

// Tasks 4 and 5: sum of multiples of 3 or 5 from n to 1
void iterativeSum()
{
	int n, sum = 0;

	cout << "Enter n here: ";
	cin >> n;

	for (; n > 0; --n)
		if (n % 3 == 0 or n % 5 == 0)
			sum += n;

	cout << "Sum of the numbers divisible by 3 or 5 from 1 to n is: " << sum;
}

// Tasks 4 and 5 again using recursion as an alternate solution
int addNumbers(int n)
{
	if (n == 0)
		return 0;
	else
		if (n % 3 == 0 or n % 5 == 0)
			return n + addNumbers(n - 1);
		else
			return addNumbers(n - 1);
}

void recursiveSum()
{
	int n, sum = 0;

	cout << "Enter n here: ";
	cin >> n;

	sum = addNumbers(n);

	cout << "Sum of the numbers divisible by 3 or 5 from 1 to n is: " << sum;
}

// Task 6: A choice of sum of product of numbers 1 to n
int sum(int n)
{
	int sum = 0;

	for (; n > 0; --n)
		sum += n;

	return sum;
}

int product(int n)
{
	int product = 1;

	for (; n > 0; --n)
		product *= n;

	return product;
}

void sumOrProduct()
{
	int n;
	string choice;

	cout << "Enter n here: ";
	cin >> n;

	cout << "Enter \"Sum\" or \"Product\": ";
	cin >> choice;

	if (choice == "Sum")
		cout << sum(n);
	else if (choice == "Product")
		cout << product(n);
	else
		cout << "Invalid choice";
}

// Task 7: Print multiplication tables up to 12
void multiplicationTable(int n)
{
	for (int i = 1; i <= 11 ;++i)
		cout << n*i << ", ";
	cout << n*12;
}

void whichTable()
{
	int n;

	cout << "Which multiplication table would you like to print (please enter a number)? ";
	cin >> n;

	multiplicationTable(n);
}

// Task 8: Print all prime numbers (I'm going to assume this one doesn't actually mean ALL prime numbers and just go up to a user selected number)

/* Initially completed this problem by iterating over every number between the tested number and 1 to see if it was divisible by any number other
 * than 1 or itself. Improved the efficiency around tenfold by storing all previously found primes in a vector and only checking if it was divisible
 * by any of them, since any other number will be a multiple of one of the prime numbers, and therefore can't be divisible by the test number if
 * prime isn't. Then further improved the efficiency by specifying that only primes up to the half the tested number should be attempted to divide
 * into it.
 */

/* Confirmed to work correctly by producing the correct number of primes between 0 and 1 million (78,498) and the correct largest prime under
 * million (999,983)
 */
void printPrimes(int n)
{
	vector <int> primes(1);
	primes[0] = 2;
	cout << primes[0] << endl;

	for (int i = 3; i <= n ; ++i)
		for (unsigned int j = 0; ; ++j)
			if (i % primes[j] == 0)
				break;
			else if (j == primes.size() - 1 or primes[j] > i/2) {
				primes.push_back(i);
				cout << i << endl;
				break;
			}
}

void setPrimeLimit()
{
	int n;

	cout << "What is the maximum limit that you want to test for prime numbers? ";
	cin >> n;

	printPrimes(n);
}

/* Task 9: Guessing game where user guesses a number and the program gives feedback on whether the number is too small or too large. When the number
 * is guessed correctly the program prints the number of guesses it took. Duplicate guesses are NOT counted to the final total.
 */

void guessingGame()
{
	int n = (rand() % 100) + 1; // Random number from 1 to 100
	int guess = 0;
	vector <int> guessedNumbers;

	while (guess != n) {
		cout << "Please enter a guess: ";
		cin >> guess;
		if (guess > n) {
			cout << "Too High" << endl;
		} else if (guess < n) {
			cout << "Too Low" << endl;
		} else if (guess == n) {
			cout << "Correct!" << endl;
		}
		guessedNumbers.push_back(guess);
	}

	sort(guessedNumbers.begin(), guessedNumbers.end()); // Sorts the vector
	guessedNumbers.erase( unique( guessedNumbers.begin(), guessedNumbers.end()), guessedNumbers.end()); // deletes the non unique elements of the vector

	cout << "There were " << guessedNumbers.size() << " unique guesses";
}

// Task 10: Print the next 20 leap years (altered to print the next n leap years).
void leapYears(int n)
{
	int leapYears[n] = {2020};

	for (int j = 1; j < n ; ++j) {
		for (int i = 1; leapYears[j] == 0 ; ++i) {
			if ((leapYears[j-1] + i*4) % 100 == 0 and (leapYears[j-1] + i*4) % 400 != 0) {
				;
			} else {
				leapYears[j] = leapYears[j-1] + i*4;
			}
		}
	}

	cout << "The next " << n << " leap years are:" << endl;
	for (int k = 0; k < n ; ++k) {
		cout << leapYears[k] << endl;
	}
}

int main()
{
	return 0;
}
