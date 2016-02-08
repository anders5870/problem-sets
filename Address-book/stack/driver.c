
int main(){
  stack_init();
  printf("%d\n", stack_count());
  stack_push(5);
  stack_push(2);
  stack_push(10);
  printf("%d\n", stack_count());
 
  stack_dup();
  stack_add();
  printf("%d\n", stack_count());
  int x;
  puts("");
  while(!stack_empty()){
    x = stack_pop();
    printf("%d\n", x);
  }
  
  return 0;
}
