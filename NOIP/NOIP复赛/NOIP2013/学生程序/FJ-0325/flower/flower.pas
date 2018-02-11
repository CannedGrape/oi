var h:array[0..100001]of longint;
    f:array[0..100001,0..2]of longint;
    i,j,n,k,z,ans:longint;
procedure find;
var i,j:longint;
begin
  for z:=2 to n do
    for j:=1 to z-1 do
      begin
        if ((h[z]>f[j,2])and(f[j,1]>f[j,2]))or((h[z]<f[j,2])and(f[j,1]<f[j,2]))and(f[j,0]+1>f[z,0])and(f[j,0] mod 2=0) then
          begin
            f[z,0]:=f[j,0]+1;
            f[z,1]:=f[j,2];
            f[z,2]:=h[z];
            if f[z,0]>ans then ans:=f[z,0];
          end;
        if (f[j,0] mod 2<>0)and(f[j,0]+1>f[z,0]) then
          begin
            f[z,0]:=f[j,0]+1;
            f[z,1]:=f[j,2];
            f[z,2]:=h[z];
            if f[z,0]>ans then ans:=f[z,0];
          end;
      end;
end;

begin
  assign(input,'flower.in');  reset(input);
  assign(output,'flower.out');  rewrite(output);
  readln(n); ans:=1;
  for i:=1 to n do read(h[i]);
  f[1,0]:=1; f[1,1]:=0; f[1,2]:=h[1];
  find;
  writeln(ans);
  close(input); close(output);
end.
