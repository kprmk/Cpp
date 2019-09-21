#pragma once

class Kettle
{
private:
	unsigned total_volume;
	unsigned cur_volume;
	float cur_temp;

public:
	Kettle();
	Kettle(unsigned cur_vol);
	~Kettle();

	unsigned get_tv() { return total_volume; };
	unsigned get_cv() { return cur_volume; };
	unsigned get_ct() { return cur_temp; };

	void vol_up();
	void boil();
	void cup_of(unsigned down);
	void cool_down(unsigned time);
	float exp_pow(unsigned time);
};

