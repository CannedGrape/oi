program level;
var
  n,m,i,j,k,num:longint;
  a:array[1..1000,0..1000] of longint;
  f:array[1..1000] of boolean;
  f1,f2:boolean;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      read(a[i,0]);
      for j:=1 to a[i,0] do read(a[i,j]);
    end;

  fillchar(f,sizeof(f),false);
  k:=1;
  for i:=1 to a[1,0] do
    begin
      f[a[1,i]]:=true;
      if a[1,i] = 1 then inc(k)
      else num:=2;
    end;

  for i:=2 to m do
    begin
      f1:=true;
      for j:=1 to a[i,0] do
        begin
          if not(f[a[i,j]]) then
            begin
              f2:=true;
            end
          else if f[a[i,j]] then
            begin
              f1:=false;
            end;
        end;
      if not(f1) and f2 then num:=num+1;
    end;

  writeln(num);
  close(input);close(output);
end.
