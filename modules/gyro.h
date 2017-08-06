class Gyro
{
 private:
  int file_i2c;
	int length;
  int chan;
	char buffer[60] = {0};
	char *filename;
 public:
  Gyro(char* bus);
  unsigned char getData();
};