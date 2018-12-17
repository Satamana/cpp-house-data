#pragma once
class human
{
	char *fio = nullptr;
public:
	human() = default;
	human(char *);
	human(const human &);
	human(human &&);
	human& operator=(const human &);
	void sethuman(char *);
	char *gethum() { return this->fio; }
	~human() { delete[] this->fio; }
};
void get(char *&);