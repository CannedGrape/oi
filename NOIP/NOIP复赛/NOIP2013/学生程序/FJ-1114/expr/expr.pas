var
  i,fhjs,szjs,js,szbh,szsl,ans:longint;
  sr:array[1..1000000000]of char;
  fh:array[1..100000]of char;
  sz,jis:array[1..100001]of int64;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
  for i:=1 to 100001 do
    sz[i]:=0;
  fhjs:=1;js:=1;szjs:=0;szsl:=0;
  for i:=1 to 6 do
    while not eoln do begin
      inc(szjs);read(sr[szjs]);
      if (sr[szjs]='+')or(sr[szjs]='*') then begin
        inc(js); fh[fhjs]:=sr[szjs];inc(fhjs);end
      else begin
        val(sr[szjs],szbh);sz[js]:=sz[js]*10+szbh;end;
    end;
  for i:=1 to fhjs do
    if fh[i]='*' then begin
      sz[i+1]:=sz[i]*sz[i+1];
      sz[i]:=0;
      end;
  for i:=1 to fhjs do
    if sz[i]<>0 then begin
      inc(szsl); jis[szsl]:=sz[i];
      end;
	
  for i:=1 to szsl do begin
    ans:=ans+jis[i];
    if ans>10000 then ans:=ans mod 10000;
  end;
  writeln(ans);
close(input);close(output);
end.