program circle;
var
  a:array[0..1000000]of longint;
  i,j,n,m,k,x,q:longint;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  read(n,m,k,x);
  fillchar(a,sizeof(a),0);
  a[0]:=1;a[x]:=2;

  q:=n;
  while q>=10 do
    q:=n mod 10;

  for i:=1 to q do
    begin
     for j:=0 to n-1 do
       if a[j]=2 then
         begin
           a[j]:=1;
           if j+x>n-1 then
             a[n-j+x-1]:=2
             else
               a[j+x]:=2
         end;
    end;

  for i:=0 to n-1 do
    if a[i]=2 then
      write(i);
  close(input);
  close(output);
end.

