var s,anss:ansistring;
    i,j,l,t,code,x,y,lx,ly,ans:longint;
function find_left(x:longint):longint;
 var i:longint;
     s1:ansistring;
  begin
   s1:='';dec(x);
   for i:=x downto 1 do
    begin
     if (s[i]='*') or (s[i]='+') then break;
     s1:=s[i]+s1;lx:=i;
    end;
   val(s1,find_left,code);
  end;
function find_right(x:longint):longint;
 var i:longint;
     s1:ansistring;
  begin
   s1:='';inc(x);
   for i:=x to l do
    begin
     if (s[i]='*') or (s[i]='+') then break;
     s1:=s1+s[i];ly:=i;
    end;
   val(s1,find_right,code);
  end;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
 readln(s);
 t:=pos('*',s);
 while t<>0 do
  begin
   l:=length(s);
   x:=find_left(t);
   y:=find_right(t);
   ans:=x*y;str(ans,anss);
   delete(s,lx,ly-lx+1);
   insert(anss,s,lx);
   t:=pos('*',s);
  end;
 t:=pos('+',s);
 while t<>0 do
  begin
   l:=length(s);
   x:=find_left(t);
   y:=find_right(t);
   ans:=x+y;str(ans,anss);
   delete(s,lx,ly-lx+1);
   insert(anss,s,lx);
   t:=pos('+',s);
  end;
 l:=length(s);anss:='';
 if l>4 then begin
  lx:=l-3;
  for i:=l downto lx do
   anss:=s[i]+anss;
  end
   else anss:=s;
 l:=length(anss);i:=1;
 while (anss[i]='0') and (l>1) do begin delete(anss,1,1);dec(l); end;
  write(anss);
close(input);close(output);
end.
