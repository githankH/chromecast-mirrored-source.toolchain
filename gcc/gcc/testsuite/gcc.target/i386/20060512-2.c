/* { dg-do compile } */
/* { dg-require-effective-target ilp32 } */
/* { dg-options "-std=gnu99 -mpreferred-stack-boundary=4" } */
int
outer_function (int x, int y)
{
  int __attribute__ ((__noinline__, __force_align_arg_pointer__))
  nested_function (int x, int y)
    {
      return (x + y);
    }
  return (3 + nested_function (x, y));
}
