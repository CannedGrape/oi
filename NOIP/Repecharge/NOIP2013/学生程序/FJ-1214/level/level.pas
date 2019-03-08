var max,n,m,i,j,m1,a2,a1,k1:longint;
    b:array[0..1001]of boolean;
    f:array[0..1001]of longint;
begin
  assign(input,'level.in'); reset(input);
  assign(output,'level.out'); rewrite(output);
  readln(n,m);   max:=0;
  for i:=1 to n do f[i]:=1;
  for i:=1 to m do
   begin
     read(m1);  fillchar(b,sizeof(b),false);
     read(a2); b[a2]:=true; k1:=a2;
     for j:=2 to m1 do
      begin
       read(a1);
       b[a1]:=true;
      end;
     j:=a2-1;
     repeat
       inc(j);
        if b[j] then  f[j]:=f[a2]
        else begin
              if f[a2]<=f[j] then
               begin
                 f[a2]:=f[j]+1;
                 j:=a2+1;
               end;
             end;
       if f[j]>max then max:=f[j];
     until j=a1;
   end;
  writeln(max);
  close(input); close(output);
end.
