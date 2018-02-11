program block;
var
  n,i,j,g,k,max,ans,tem,x:longint;    bo:boolean;
  //a:array[0..100000] of longint;
  h,d:array[0..10000] of longint;
  b1,b2:array[0..10000,0..10000] of longint;
begin
  assign(input,'block.in');  reset(input);
  assign(output,'block.out');  rewrite(output);
  readln(n);
  max:=-20000000;
  for i:=1 to n do
  begin
    read(x);
    inc(h[x]);
    if max<x then max:=x;
    inc(d[x]);
      b1[x,d[x]]:=i;
      b2[x,d[x]]:=i;
  end;
  readln;
    //writeln('max:',max);
  for i:=max downto 1 do
    begin
      j:=d[i]; //writeln('/d[i]: ',j); for g:=1 to d[i] do begin writeln(b1[i,g],' ',b2[i,g]); end;
      while j>1 do
      begin
        //writeln('b1: ',b1[i,j],' b2: ',b2[i,j]);
        if b1[i,j]=b2[i,j-1]+1 then
        begin
          b2[i,j-1]:=b2[i,j];
          for g:=j+1 to d[i] do
            begin
              b1[i,g-1]:=b1[i,g];
              b2[i,g-1]:=b2[i,g];
            end;
          dec(d[i]); //writeln('d[i]->',i,' ',d[i],' ');
        end;
        dec(j);     //writeln('j->',j,' ');
      end;
      ans:=ans+d[i]; //writeln('ans: ',ans);
      for g:=d[i-1]+1 to d[i-1]+d[i] do
        begin
          b1[i-1,g]:=b1[i,g-d[i-1]];
          b2[i-1,g]:=b2[i,g-d[i-1]];
        end;
      d[i-1]:=d[i-1]+d[i];
      g:=0;
      repeat
        bo:=true;
        inc(g);
        for k:=d[i-1] downto g+1 do
          if b1[i-1,k-1]>b1[i-1,k] then
            begin
              tem:=b1[i-1,k-1]; b1[i-1,k-1]:=b1[i-1,k]; b1[i-1,k]:=tem;
              tem:=b2[i-1,k-1]; b2[i-1,k-1]:=b2[i-1,k]; b2[i-1,k]:=tem;
              bo:=false;
            end;
      until bo;
    end;
  writeln(ans);
  close(input);  close(output);
end.