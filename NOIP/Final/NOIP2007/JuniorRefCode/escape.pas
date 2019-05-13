program a3(input,output);
var
  a,b:array[0..10000]of longint;
  m,s,t,i,j:longint;
function max(a,b,c:longint):longint;
  var
    k:longint;
  begin
    if a>b then k:=a else k:=b;
    if k<c then k:=c;
    max:=k;
  end;
begin
  assign(input,'escape.in');
  assign(output,'escape.out');
  reset(input);
  rewrite(output);
  readln(m,s,t);
  for i:=0 to 10000 do
    begin
      a[i]:=0;
      b[i]:=0;
    end;
  for i:=1 to t do
    begin
      for j:=0 to 9 do
        begin
          b[j]:=max(a[j]+17,a[j+4],0);
          if b[j]>=s then
            begin
              writeln('Yes');
              writeln(i);
              close(input);
              close(output);
              halt;
            end;
        end;
      for j:=10 to m do
        begin
          b[j]:=max(a[j]+17,a[j+4],a[j-10]+60);
          if b[j]>=s then
            begin
              writeln('Yes');
              writeln(i);
              close(input);
              close(output);
              halt;
            end;
        end;
      a:=b;
    end;
  writeln('No');
  writeln(a[m]);
  close(input);
  close(output);
end.
