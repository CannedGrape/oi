Var n,i,j,ans,t:longint;
    a:array[1..100000] of longint;
    f:array[1..100000,1..2] of longint;
Function max(x,y:longint):longint;
 begin
     if x>y then exit(x); exit(y);
 end;
Begin
        Assign(Input,'flower.in');Reset(Input);
        Assign(Output,'flower.out');Rewrite(Output);
 readln(n);
 for i:=1 to n do read(a[i]);
 f[1,1]:=1; f[1,2]:=1;
 for i:=1 to n-1 do
  begin
   for j:=i+1 to n do
    begin
     if a[j]>a[i] then f[j,1]:=max(f[j,1],f[i,2]+1);
     if a[j]<a[i] then f[j,2]:=max(f[j,2],f[i,1]+1);
    end;
  end;
 ans:=max(f[n,1],f[n,2]);
 if ans mod 2=0 then dec(ans);
 writeln(ans);
        Close(Input);Close(Output);
End.
