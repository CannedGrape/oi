program match;
var a,b:array [0..100001] of longint;
n,c,d,e,j,temp:longint;
begin
assign(input,'match.in');assign(output,'match.out');
reset(input);rewrite(output);
readln(n);fillchar(a,sizeof(a),0);fillchar(b,sizeof(b),0);

for c:=1 to n do read(a[c]);readln;
for c:=1 to n do read(b[c]);
j:=0;

if sqr(a[2]-b[1])+sqr(a[1]-b[2])<sqr(a[1]-b[1])+sqr(a[2]-b[2]) then begin
   inc(j);temp:=a[1];a[1]:=a[2];a[2]:=temp;end;

for c:=2 to n-1 do begin
  if sqr(a[c-1]-b[c])+sqr(a[c]-b[c-1])<sqr(a[c]-b[c])+sqr(a[c-1]-b[c-1]) then
       begin
       inc(j);
       temp:=a[c];
       a[c]:=a[c-1];
       a[c-1]:=temp;
       end;

  if sqr(a[c+1]-b[c])+sqr(a[c]-b[c+1])<sqr(a[c]-b[c])+sqr(a[c+1]-b[c+1]) then
  begin
  inc(j);
  temp:=a[c];
  a[c]:=a[c-1];
  a[c-1]:=temp;
  end;

end;

if sqr(a[n-1]-b[n])+sqr(a[n]-b[n-1])<sqr(a[n]-b[n])+sqr(a[n-1]-b[n-1]) then
   begin
   inc(j);
   temp:=a[n];
   a[n]:=a[n-1];
   a[n-1]:=temp;
   end;

write(j mod 99999997);

close(input);close(output);
end.
