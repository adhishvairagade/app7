//adhi
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define N 4
bool m0PrefersM1OverM(int prefer[2*N][N], int m0, int m, int m1)
{
	for (int i = 0; i < N; i++)
	{
		if (prefer[m0][i] == m1)
			return true;

		if (prefer[m0][i] == m)
		return false;
	}
}

void stable(int prefer[2*N][N])
{

	int wPartner[N];

	bool mFree[N];

	memset(m0Partner, -1, sizeof(m0Partner));
	memset(mFree, false, sizeof(mFree));
	int freeCount = N;

	while (freeCount > 0)
	{
		int m;
		for (m = 0; m < N; m++)
			if (mFree[m] == false)
				break;

		for (int i = 0; i < N && mFree[m] == false; i++)
		{
			int m0 = prefer[m][i];

			if (wPartner[m0-N] == -1)
			{
				wPartner[m0-N] = m;
				mFree[m] = true;
				freeCount--;
			}

			else {
				int m1 = wPartner[m0-N];

				if (m0PrefersM1OverM(prefer, m0, m, m1) == false)
				{
					wPartner[m0-N] = m;
					mFree[m] = true;
					mFree[m1] = false;
				}
			}
		}
	}



	cout << "Match::" << endl;
	for (int i = 0; i < N; i++)
	cout << " " << i+N << "\t" << m0Partner[i] << endl;
}

int main()
{
	int prefer[2*N][N] = { {7, 5, 6, 4},
		{5, 4, 6, 7},
		{4, 5, 6, 7},
		{4, 5, 6, 7},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
	};
	stable(prefer);

	return 0;
}
