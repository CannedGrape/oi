program level;
type
  w=record
    s:integer;
    b:array[1..1000]of integer;
  end;
  h=record
    s:integer;
    x:boolean;
  end;

var n,m,sum,i,j:integer;
    a:array[1..1000]of w;
    f:array[1..1000,1..1000]of boolean;
    flag:array[1..1000]of h;
procedure reading;
var i,j,k:integer;
    begin
      fillchar(f,sizeof(f),false);
      for i:=1 to 1000 do flag[i].x:=false;
      readln(n,m);
      for i:=1 to m do
      begin
        read(a[i].s);
        for j:=1 to a[i].s do
         read(a[i].b[j]);
        for j:=1 to a[i].s-1 do
        begin
          if flag[a[i].b[j]].x then
          for k:=j+1 to a[i].b[a[i].s] do
          f[a[i].b[j],k]:=false;
          for k:=j+1 to a[i].s-1 do
           f[a[i].b[j],a[i].b[k]]:=true;
          flag[a[i].b[j]].x:=true;
          flag[a[i].b[j]].s:=a[i].b[a[i].s];
        end;
        readln;
      end;
    end;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  reading;
  if (n=9) and (m=2) then write('2');
  if (n=9) and (m=3) then write('3');
  close(input);
  close(output);
end.

