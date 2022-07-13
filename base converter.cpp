#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

//base [2,36] to base 10
double functie(int b, char n[])
{
	int p = 0, i, k, m, ok = 0;
	double j = 0, a = 0;

	i = -1;
	m = strlen(n) - 1;
	while (i <= m)
	{
		i++;
		k = n[i];
		if (k <= 57 && k != 46 && k != 45)
			k = k - 48;
		else if (k >= 65)
			k = k - 55;
		if (k >= b && k != 46 && k !=45)
		{
			cout << "Eroare.Reintroduceti numarul:";
			i = -1;
			cin >> n;
			m = strlen(n) - 1;
		}
	}
	if (n[0] == '-')
	{
		strcpy_s(n, 50, n + 1);
		ok = 1;
	}

	for (i = 0; i <= strlen(n) - 1; i++)
	{
		if (n[i] == '.')
		{
			p = i - strlen(n) + 1;
			break;
		}
	}

	for (i = strlen(n) - 1; i >= 0; i--)
	{
		k = n[i];
		if (k <= 57 && k != 46)
			k = k - 48;
		else if (k >= 65)
			k = k - 55;
		else if (k == 46)
		{
			j = a;
			a = 0;
		}
		if (n[i] != 46)
		{
			a = a + k*pow(b, p);
			p++;
		}
	}

	double g;
	g = a + j;
	if (ok == 1)
		g = g*(-1);

	return g;
}

//base 10 to base [2,36]
char* functie1(int b, double n)
{
	int i, j, p = -1, n1, ok = 0;
	double n2 = 0;
	char c[100], a[100];

	if (n < 0)
	{
		ok = 1;
		n = n*(-1);
	}

	if (n == (int)n)
	{
		n1 = n;
	}
	else
	{
		n1 = (int)n;
		n2 = n - (int)n;
	}

	if (n2 == 0)
	{
		while (n1 != 0) {
			int r = n1 % b;
			n1 = n1 / b;
			p++;
			if (r <= 9)
				r = r + 48;
			else
				r = r + 55;
			c[p] = r;
		}

		for (i = p; i >= 0; i--)
		{
			a[p - i] = c[i];
		}

		a[p + 1] = NULL;

	}
	else
	{
		if (n1 == 0)
		{
			p++;
			a[p] = '0';
			p++;
			a[p] = '.';
		}
		else
		{
			while (n1 != 0) {
				int r = n1 % b;
				n1 = n1 / b;
				p++;
				if (r <= 9)
					r = r + 48;
				else
					r = r + 55;
				c[p] = r;
			}

			for (i = p; i >= 0; i--)
			{
				a[p - i] = c[i];
			}
			p++;
			a[p] = '.';
		}
		while (n2 != (int)n2)
		{
			n2 = n2 * b;
			p++;
			if ((int)n2 <= 9)
				a[p] = (int)n2 + 48;
			else
				a[p] = (int)n2 + 55;
			n2 = n2 - floor(n2);
		}


	}

	if (ok == 1)
	{
		p++;
		for (i = p; i >= 0; i--)
			a[i] = a[i - 1];
		a[0] = '-';
	}
	a[p + 1] = NULL;
	return a;
}

int main()
{
	int b, c, ok = 0;
	char n[100], a[100];
	double n1;
	for (;;) {
		cout << "Baza in care se afla numarul este:";
		cin >> b;
		while (b < 2 || b>36)
		{
			cout << "Eroare. Reintroduceti baza:";
			cin >> b;
		}
		cout << "Baza in care trebuie convertit numarul este:";
		cin >> c;
		while (c < 2 || c>36)
		{
			cout << "Eroare. Reintroduceti baza:";
			cin >> c;
		}
		if (c == 10)
		{
			cout << "Numarul in baza " << b << " este:";
			cin >> n;
			cout << "Numarul din baza " << b << " convertit in baza " << c << " este:" << functie(b, n);
		}
		else if (b == 10)
		{
			cout << "Numarul in baza " << b << " este:";
			cin >> n1;
			strcpy_s(n, 50, functie1(c, n1));
			cout << "Numarul din baza " << b << " convertit in baza " << c << " este:" << n;

		}
		else
		{
			cout << "Numarul in baza " << b << " este:";
			cin >> n;
			double k1;
			k1 = functie(b, n);
			strcpy_s(a, 50, functie1(c, k1));
			cout << "Numarul din baza " << b << " convertit in baza " << c << " este:" << a;
		}
		cout << endl << endl;
	}

	_getch();
	return 0;
}