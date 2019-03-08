var n,m,aa,bb,aaa,bbb:longint;
    a,b,h:array[0..100001]of longint;

procedure fopen;
begin
 assign(input,'flower.in');
 assign(output,'flower.out');
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
 if(n=1)or(n=2)then
  begin
   writeln(n);
   fclose;
   halt;
  end;
 for i:=2 to n-1 do
  begin
   if(h[i]>h[i-1])and(h[i]>h[i+1])then
    begin
     inc(aa);
     a[aa]:=i;
    end;
   if(h[i]<h[i-1])and(h[i]<h[i+1])then
    begin
     inc(bb);
     b[bb]:=i;
    end;
  end;
 aaa:=aa*2+1;
 bbb:=bb*2+1;
 if aaa>bbb then
  writeln(aaa)
 else writeln(bbb);
end;

begin
 fopen;
 main;
 fclose;
end.
