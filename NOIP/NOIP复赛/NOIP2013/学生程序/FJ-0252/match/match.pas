program match;
var
  a,b:array[1..100000]of longint;
  ans,i,j,n,min,count:longint;
  input,output:text;
procedure swap(x,y:longint);
var
  i,temp:longint;
begin
  if x<y then
    begin
      temp:=b[y];
      for i:=y downto x-1 do
        b[i]:=b[i-1];
      b[x]:=temp;
    end;
end;

begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
  read(input,n);
  for i:=1 to n do
    read(input,a[i]);
  for i:=1 to n do
    read(input,b[i]);
  close(input);
  for i:=1 to n do
    begin
      count:=0;
      for j:=i div 2 to n do
        if abs(b[j]-a[i])<=min then
          begin
            count:=j;
            min:=abs(b[j]-a[i]);
          end;
      ans:=(ans+abs(i-count))mod 99999997;
      swap(i,count);
    end;
  write(output,ans);
  close(output);
end.
