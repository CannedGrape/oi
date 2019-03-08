var i,j,k,t,m,n,ans:longint;
    a,b:array[-1..100005] of longint;
begin
 assign(input,'flower.in'); reset(input);
 assign(output,'flower.out'); rewrite(output);
 readln(n);
 read(m);
 a[1]:=m; a[0]:=1; a[-1]:=-1;
 b[1]:=m; b[0]:=1; b[-1]:=1;
 for i:=2 to n do
  begin
   read(m);
   if a[-1]=-1 then
    begin
    if a[a[0]]>m then begin inc(a[0]); a[a[0]]:=m; a[-1]:=-a[-1]; end
     else a[a[0]]:=m;
    end
   else
    if a[a[0]]<m then begin inc(a[0]); a[a[0]]:=m; a[-1]:=-a[-1]; end
      else a[a[0]]:=m;
   if b[-1]=-1 then
    begin
    if b[b[0]]>m then begin inc(b[0]); b[b[0]]:=m; b[-1]:=-b[-1]; end
     else b[b[0]]:=m;
    end
   else
    if b[b[0]]<m then begin inc(b[0]); b[b[0]]:=m; b[-1]:=-b[-1]; end
     else b[b[0]]:=m;
  end;
 ans:=a[0];
 if b[0]>ans then ans:=b[0];
 writeln(ans);
 close(input); close(output);
end.