var
  sta,n,m,i,j,re,ans:longint;
  a,lev:array[0..5000] of longint;
  b:array[0..5000] of boolean;
  bo:boolean;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(sta,n);
  for i:=1 to n do begin
    read(m);
    re:=0; bo:=false;
    for j:=1 to m do begin read(a[j]); b[a[j]]:=true;if lev[a[j]]<>0 then if (lev[a[j]]=re) or (re=0) then re:=lev[a[j]] else bo:=true; end;
    for j:=a[1]+1 to a[m]-1 do if (lev[j]>=re) and (b[j]=false) then begin bo:=true; break; end;
    if (re=0) or (bo=true) then begin inc(ans); for j:=1 to m do lev[a[j]]:=ans; end
    else for j:=1 to m do lev[a[j]]:=re;
    readln;
    for j:=1 to m do b[a[j]]:=false;
  end;
  writeln(ans+1);
  close(input);
  close(output);
end.
