#include <iostream>
#include "wavfile.h"
using namespace std;

void allocateArray(unsigned char*& arr, int size);
void deallocateArray(unsigned char*& arr);
void printArray(unsigned char* arr, int size);
void playfile(char* str);
unsigned char* readFromFile(char* str, int& sampleRate, int& size);
unsigned char* doubleArray(unsigned char* ptr, int size, int& upSize);
void upSampleAudio(char* str, unsigned char* ptr, int size, int sampleRate);
unsigned char* shrinkArray(unsigned char* arr,int size, int& downSize);
void downSampleAudio(char* str, unsigned char* ptr, int size, int sampleRate);
void FillWithMean(unsigned char* in, int size, unsigned char* out, int N);
void movingAverageFilter(char* str, unsigned char* arr, int size, int sampleRate);
void mergeArray(unsigned char* arr, int size, unsigned char* arr2, int size2, unsigned char* arr3);
void menu();

int main()
{
	menu();
}

void menu()
{
	cout << "MENU" << endl;
	cout << "Please Enter: " << endl;
	cout << "0 - to exit the program. " << endl;
	cout << "1 - to read an audio file. " << endl;
	cout << "2 - to print data of audio file read as integers." << endl;
	cout << "3 - to up sample audio file." << endl;
	cout << "4 - to down sample audio file." << endl;
	cout << "5 - to apply moving average filter to the audio file." << endl;
	cout << "6 - to mix two audio files together." << endl;

	int option = -1;
	cin >> option;
	cout << endl;
	char str[50] = "";
	int sampleRate = 0, size = 180000;
	unsigned char* data = nullptr;

	while (option != 0)
	{
		switch (option)
		{
		case 1:
		{
			cout << "Enter file name with (.wav) or exit: ";
			cin >> str;
			data = readFromFile(str, sampleRate, size);
			playfile(str);
			break;
		}

		case 2:
			printArray(data, size);
			break;

		case 3:
			upSampleAudio(str, data, size, sampleRate);
			break;

		case 4:
			downSampleAudio(str, data, size, sampleRate);
			break;

		case 5:
			movingAverageFilter(str, data, size, sampleRate);
			break;

		case 6:
		{
			cout << "Enter 1st file's name with (.wav) or exit: ";
			cin >> str;
			int s1 = 800000, srate1 = 0;
			unsigned char* arr1 = nullptr;
			allocateArray(arr1, s1);
			arr1 = readFromFile(str, srate1, s1);

			cout << endl;
			cout << "Enter 2nd file's name with (.wav) or exit: ";
			cin >> str;
			int s2 = 800000, srate2 = 0;
			unsigned char* arr2 = nullptr;
			allocateArray(arr2, s2);
			arr2 = readFromFile(str, srate2, s2);

			unsigned char* arr3 = nullptr;
			int s3 = s1 + s2;
			allocateArray(arr3, s3);
			mergeArray(arr1, s1, arr2, s2, arr3);

			char fname1[22] = "mergedSampleRate1.wav";
			writeWavFile(fname1, arr3, s3, srate1);

			char fname2[22] = "mergedSampleRate2.wav";
			writeWavFile(fname2, arr3, s3, srate2);

			deallocateArray(arr1);
			deallocateArray(arr2);
			deallocateArray(arr3);
			break;
		}
		}
		
		cout << endl;
		cout << "MENU" << endl;
		cout << "Please Enter: " << endl;
		cout << "0 - to exit the program. " << endl;
		cout << "1 - to read an audio file. " << endl;
		cout << "2 - to print data of audio file read as integers." << endl;
		cout << "3 - to up sample audio file." << endl;
		cout << "4 - to down sample audio file." << endl;
		cout << "5 - to apply moving average filter to the audio file." << endl;
		cout << "6 - to mix two audio files together." << endl;
		cin >> option;
		cout << endl;
	}
	deallocateArray(data);
}

void allocateArray(unsigned char*& arr, int size)
{
	arr = new unsigned char[size];
}

void deallocateArray(unsigned char*& arr)
{
	delete[] arr;
	arr = nullptr;
}

void printArray(unsigned char* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << (int)*(arr + i) << " ";
}

void playfile(char* str)
{
	if (playWavFile(str) == 0)
		cout << "Error: File not found!" << endl;
}

unsigned char* readFromFile(char* str, int& sampleRate, int& size) 
{
	unsigned char* ptr = nullptr;
	allocateArray(ptr,size);
	readWavFile(str, ptr, size, sampleRate);
	return ptr;
}

unsigned char* doubleArray(unsigned char* arr, int size, int& upSize)
{
	upSize = size * 2;

	unsigned char* arr2 = nullptr;
	allocateArray(arr2, upSize);

	int i, j;
	for (i = 0, j = 0; i < upSize - 1 && j < size; i = i + 2, j++)
	{
		arr2[i] = arr[j];
		arr2[i + 1] = arr[j];
	}
	return arr2;
}


void upSampleAudio(char* str, unsigned char* ptr,int size, int sampleRate)
{
	int upSize;
	unsigned char* doubleS = nullptr;
	doubleS = doubleArray(ptr, size, upSize);
	char fname[15] = "upSample.wav";
	writeWavFile(fname, doubleS, upSize, sampleRate);
	playfile(fname);
	deallocateArray(doubleS);
	//Observation: The output audio is slowed down and has a lower pitch
}

unsigned char* shrinkArray(unsigned char* arr, int size, int& downSize)
{
	if (size % 2 == 0)
		downSize = size / 2;
	else
		downSize = (size / 2) + 1;

	unsigned char* arr2 = nullptr;
	allocateArray(arr2, downSize);

	int i, j;
	for (i = 0, j = 0; i < downSize; i++, j = j + 2)
	{
		arr2[i] = arr[j];
	}

	return arr2;
}

void downSampleAudio(char* str, unsigned char* ptr, int size, int sampleRate)
{
	int downSize;
	unsigned char* shrink = nullptr;
	shrink = shrinkArray(ptr, size, downSize);
	char fname[15] = "downSample.wav";
	writeWavFile(fname, shrink, downSize, sampleRate);
	playfile(fname);
	deallocateArray(shrink);
	//Observation: The output audio is fast-forwarded and has a higher pitch
}

void FillWithMean(unsigned char* in, int size, unsigned char* out, int N)
{
	int i, j, k;
	for (i = 0; i < size; i++)
	{
		int sum = 0;
		for (j = i; j <= i + N && j < size; j++)
		{
			sum = sum + in[j];
		}

		for (k = i - 1; k >= 0 && k >= i - N; k--)
		{
			sum = sum + in[k];
		}

		out[i] = sum / ((j - i) + (i - (k + 1)));
	}
}

void movingAverageFilter(char* str, unsigned char* arr, int size, int sampleRate)
{
	unsigned char* mean = nullptr;
	allocateArray(mean, size);
	int N = 10;                      // value can be changed to alter output
	FillWithMean(arr,size,mean,N);
	char fname[20] = "avgFilter.wav";
	writeWavFile(fname,mean,size,sampleRate);
	playfile(fname);
	deallocateArray(mean);
	//Observation: The quality of output audio decreases. The larger the value of N, the greater the reduction in quality.
}


void mergeArray(unsigned char* arr, int size, unsigned char* arr2, int size2, unsigned char* arr3)
{
	int i, j;
	for (i = 0, j = 0; i < size + (size - 1) && i < size2 + (size2 - 1); i = i + 2, j++)
	{
		arr3[i] = arr[j];
		arr3[i + 1] = arr2[j];
	}
	while (j < size)
	{
		arr3[i] = arr[j];
		i++;
		j++;
	}
	while (j < size2)
	{
		arr3[i] = arr2[j];
		i++;
		j++;
	}
	//Observation: In the file saved with the sample rate of dhani, the merged part of sallimono.wav is greatly slowed down.
}   //             In the file saved with the sample rate of sallimono.wav, the merged part of dhani is sped up. 
