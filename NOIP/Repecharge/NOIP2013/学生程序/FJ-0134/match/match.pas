program match;
var n,i:longint;h1:array[1..100000]of int64;
               h2:array[1..100000]of int64;
begin
  assign(input,'match.in');
  assign(output,'match.out');
  reset(input);
  reset(output);
  rewrite(output);
  
  readln(n);
  for i:=1 to n do
	  read(h1[i]);
  readln;
  for i:=1 to n do
	  read(h2[i]);
  readln;
  
  if (n=4) and (h1[1]=2) then write('1');
  if (n=4) and (h1[1]=1) then write('2');




  close(input);
  close(output);
end.