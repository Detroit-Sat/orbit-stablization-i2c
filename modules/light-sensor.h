class LightSensor
{
 private:
  int file_i2c;
	int length;
  int chan;
	char buffer[60] = {0};
	char *filename;
 public:
  LightSensor(char* bus, int channel);
  unsigned char getData();
};