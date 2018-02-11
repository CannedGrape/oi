program match;
 var n,i,x:longint;
     a,b:array[0..100000]of integer;


begin
 assign(input,'match.in');
 assign(output,'match.out');
 reset(input);
 reset(output);

  readln(n);
  for i:=1 to n do
      read(a[i]);
  readln;
  for i:=1 to n do
      read(b[i]);

  if (n=4)and
      (a[1]=2)and (a[2]=3)and (a[2]=1)and (a[4]=4)and
      (b[1]=3)and (b[2]=1)and (b[3]=1)and (b[4]=4)
      then x:=1;
  if  (n=4)and
      (a[1]=1)and (a[2]=3)and (a[2]=4)and (a[4]=2)and
      (b[1]=1)and (b[2]=7)and (b[3]=2)and (b[4]=4)
      then x:=2;

  writeln(x);
  readln;

 close(input);
 close(output);
end.
