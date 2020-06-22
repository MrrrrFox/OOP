#pragma once

typedef float english; // english zwraca dokładnie to samo co float, więc wystarczy typedef

// klasa polish
class polish
{
private:
	int _cale;
public:
	polish(int);
	float operator,(int) const;
};

