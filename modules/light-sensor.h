class LightSensor
{
 private:
  int file_i2c;
	int length;
  int addr;
	unsigned char buffer[60] = {0};
	char *filename;
 public:
  LightSensor(char* bus, int address);
  unsigned char getData();
};