#define INT_DIGITS 19		/* enough for 64 bit integer */
#define UINT_DIGITS 20

#ifdef __cplusplus
extern "C" {
#endif

char *i_to_a(int i)
{
  /* Room for INT_DIGITS digits, - and '\0' */
  static char buf[INT_DIGITS + 2];
  char *p = buf + INT_DIGITS + 1;	/* points to terminating '\0' */
  if (i >= 0) {
    do {
      *--p = '0' + (i % 10);
      i /= 10;
    } while (i != 0);
    return p;
  }
  else {			/* i < 0 */
    do {
      *--p = '0' - (i % 10);
      i /= 10;
    } while (i != 0);
    *--p = '-';
  }
  return p;
}

char *ui_to_a(unsigned int i)
{
  /* Room for UINT_DIGITS digits and '\0' */
  static char buf[UINT_DIGITS + 1];
  char *p = buf + UINT_DIGITS;	/* points to terminating '\0' */
  do {
    *--p = '0' + (i % 10);
    i /= 10;
  } while (i != 0);
  return p;
}

#ifdef __cplusplus
}
#endif
