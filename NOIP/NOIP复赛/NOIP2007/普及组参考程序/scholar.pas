program a1(input,output);
var
  n,x,y,z,i,j:integer;
  a:array[1..300,1..3] of integer;
procedure swap(var a,b:integer);
  var
    s:integer;
  begin
    s:=a;
    a:=b;
    b:=s;
  end;
begin
  assign(input,'scholar.in');
  assign(output,'scholar.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      readln(x,y,z);
      a[i,1]:=i;
      a[i,2]:=x;
      a[i,3]:=x+y+z;
    end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (a[i,3]<a[j,3]) or ((a[i,3]=a[j,3]) and (a[i,2]<a[j,2])) or ((a[i,1]>a[j,1]) and (a[i,3]=a[j,3]) and (a[i,2]=a[j,2])) then
        begin
          swap(a[i,1],a[j,1]);
          swap(a[i,2],a[j,2]);
          swap(a[i,3],a[j,3]);
        end;
  for i:=1 to 5 do
    writeln(a[i,1],' ',a[i,3]);
  close(input);
  close(output);
end.
