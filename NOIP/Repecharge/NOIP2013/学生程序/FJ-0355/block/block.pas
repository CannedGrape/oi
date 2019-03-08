Program mxpiii;
Var
  a:array[0..100010] of longint;
  n,i,j,k,_min,ans,s:longint;

Function min(x,y:longint):longint;
Var
   i:longint;
Begin
  for i:=x to y do if a[i]<_min then _min:=a[i];
  min:=_min;
End;

Begin
   assign(input,'block.in');
   assign(output,'block.out');
   reset(input);
   rewrite(output);
   readln(n); s:=0; ans:=0;
   for i:=1 to n do begin read(a[i]); s:=s+a[i]; end;
   i:=1;
   while s<>0 do
   begin
     while (a[i]=0) and (i<=n) do inc(i);
     if i>n then break;
     _min:=maxlongint;
     for j:=n downto i do
       if min(i,j)<>0 then break else _min:=maxlongint;
     ans:=ans+_min;
     for k:=i to j do a[k]:=a[k]-_min;
     s:=0;
     for j:=1 to n do s:=s+a[j];
   end;
   writeln(ans);
   close(input);
   close(output);
End.
