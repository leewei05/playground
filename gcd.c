#include <stdint.h>
#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

uint64_t gcd64(uint64_t u, uint64_t v) {
  if (!u || !v)
    return u | v;
  int u_ctz = __builtin_ctzll(u);
  int v_ctz = __builtin_ctzll(v);
  u >>= u_ctz;
  v >>= v_ctz;
  do {
    if (u < v) {
      v -= u;
    } else {
      uint64_t t = u - v;
      u = v;
      v = t;
    }
  } while (v);
  return u << MIN(u_ctz, v_ctz);
}

int main() {
  printf("48, 64, %lld", gcd64(48, 64));
  printf("38, 133, %lld", gcd64(38, 133));
}
