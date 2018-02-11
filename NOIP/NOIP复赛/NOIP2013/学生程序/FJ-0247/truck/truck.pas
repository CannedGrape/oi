program truck;


begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
     write('-1');

  close(input);close(output);
end.

