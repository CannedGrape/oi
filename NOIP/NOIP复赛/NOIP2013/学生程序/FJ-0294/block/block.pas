var i,j,k,t,m,n:longint;    ans:qword;
    h:array[0..100005] of longint;
begin
 assign(input,'block.in'); reset(input);
 assign(output,'block.out'); rewrite(output);
 readln(n);   h[0]:=0;  ans:=0;
 for i:=1 to n do
  begin
   read(h[i]);
   if h[i]>h[i-1] then ans:=ans+h[i]-h[i-1];
  end;
 writeln(ans);
 close(input); close(output);
end.