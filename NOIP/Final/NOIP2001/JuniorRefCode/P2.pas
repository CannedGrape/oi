Program fq01_p2; {2001分区联赛普及组第2题}
var
  ans,x,y,z,p,k:longint;
  i:integer;

  begin
    readln(x,y);
    if(y mod x<>0)then
    begin
      writeln(0); {无解}
      exit;
    end;
    z := y div x;
    p:=2;
    k:=0;
    while(z>1) do
    begin
      if(z mod p=0) then
      begin
        inc(k);
        while(z mod p=0) do z:=z div p;        
      end;
      inc(p);                  
    end;
    ans:=1; {计算ans=2^k}
    for i:=1 to k do
      ans:=ans*2;
    writeln(ans);
  end.
