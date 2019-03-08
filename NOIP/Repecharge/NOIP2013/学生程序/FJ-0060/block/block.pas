var n,i,j:longint;
    ans:int64;
    a:array[0..1000000]of longint;
begin
  assign(input,'block.in');
  assign(output,'block.out');
   reset(input);
   rewrite(output);
  readln(n);
  fillchar(a,sizeof(a),0);
   for i:=1 to n do
     read(a[i]);
   for i:=1 to n do
     if a[i+1]<a[i] then ans:=ans+a[i]-a[i+1];
   writeln(ans);
  close(input);
  close(output);
end.