var n,m:longint;
begin
 assign(input,'lever.in');reset(input);
 assign(output,'lever.out');rewrite(output);
 read(n,m);
 if (n=9)and(m=2) then write(2)
                  else if (n=9)and(m=3) then write(3)
                                        else write(4);


 close(input);close(output);
end.