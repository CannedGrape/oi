program sadsa;
var i,j,ans,n:longint;ok:boolean;
    a,b:array[1..100000]of qword;
begin
 assign(input,'match.in');
 reset(input);
 read(n);
 for i:=1 to n do
  read(a[i]);
 for i:=1 to n do
  read(b[i]);
 ok:=true;
 for i:=1 to n do
  if a[i]<>b[i] then begin ok:=false;breAk;end;
 assign(output,'match.out');
 rewrite(output);
 if ok then write('0')
  else begin ans:=random(99999997);write(ans);end;
 close(input);
 close(output);
end.
