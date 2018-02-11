Var n,i,j:longint;
    ans:int64;
    a:array[0..100000] of longint;
Begin
        Assign(Input,'block.in');Reset(Input);
        Assign(Output,'block.out');Rewrite(Output);
 readln(n);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do
  if a[i]>a[i-1] then ans:=ans+a[i]-a[i-1];
 writeln(ans);
        Close(Input);Close(Output);
End.
