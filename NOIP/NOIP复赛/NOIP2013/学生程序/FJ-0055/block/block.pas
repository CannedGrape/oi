var n,ans,rr:longint;
    h,d:array[0..100001]of longint;

procedure fopen;
begin
 assign(input,'block.in');
 assign(output,'block.out');
 reset(input);
 rewrite(output);
end;
procedure fclose;
begin
 close(input);
 close(output);
end;

procedure main;
var i:longint;
begin
 readln(n);
 for i:=1 to n do read(h[i]);
 d[1]:=h[1];
 ans:=d[1];
 rr:=1;
 for i:=2 to n do
  if h[i]>d[rr] then
   begin
    inc(ans,h[i]-d[rr]);
    inc(rr);
    d[rr]:=h[i];
   end
  else begin
   while(rr>0)and(d[rr]>=h[i])do
    dec(rr);
   inc(rr);
   d[rr]:=h[i];
  end;
 writeln(ans);
end;

begin
 fopen;
 main;
 fclose;
end.