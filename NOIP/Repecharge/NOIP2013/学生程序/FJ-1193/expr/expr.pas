var
  zuo,you,shi,fu,ans:string;
  w1,w2,kan,i,j,wei,c,pan,p1,p2,p3:longint;
procedure chuli(p,q:longint);
begin
  wei:=pos('*',shi);
    if wei=0 then
    begin
      wei:=pos('+',shi);
      zuo:=copy(shi,p,wei-p);
      you:=copy(shi,wei+1,q-wei);
      pan:=pos('+',you);
      if pan<>0 then
      begin
        you:=copy(shi,wei+1,pan-wei);
        ans:=ans+zuo+you;
        shi:=copy(shi,pan,q-pan);
        pan:=0;
      end else ans:=ans+zuo+you;
    end;
end;
begin
  assign(input,'expr.in'); reset(input);
  assign(output,'expr.out'); rewrite(output);
  readln(shi);
  c:=length(shi);
  chuli(1,c);
  if length(ans)<=4 then writeln(ans) else
  begin
    if copy(ans,length(ans)-4,1)<>'0' then writeln(copy(ans,length(ans)-4,4))
    else
    if copy(ans,length(ans)-3,1)<>'0' then writeln(copy(ans,length(ans)-3,3))
    else
    if copy(ans,length(ans)-2,1)<>'0' then writeln(copy(ans,length(ans)-2,2))
    else writeln(copy(ans,length(ans),1));
  end;
  close(input); close(output);
end.
