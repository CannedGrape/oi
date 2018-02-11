program Median;
  {HGF 2000-8-20}
  uses Device;
  const
    MaxN=1499;
  var
    Sort:array[1..MaxN]of Integer;
    Str :array[0..MaxN]of Integer;
    Now,n,Mid:Integer;
  procedure Insert(l,r:Integer);
    var
      d,l0,r0,i:Integer;
    begin
      if (l+1=r) or (l>=Mid)
      then begin
             for i:=Now downto r+1 do Sort[i]:=Sort[i-1];
             Sort[r]:=Now
           end
      else begin
             l0:=l+(r-l+1) div 3;
             r0:=r-(r-l+1) div 3;
             if l0=r0
             then if l=0
                  then begin
                         d:=Med3(Now,Sort[r0],Sort[r]);
                         if d=Now      then Insert(r0,r) else
                         if d=Sort[r0] then Insert(l,r0)
                                       else WriteLn('Error!')
                       end
                  else begin
                         d:=Med3(Now,Sort[l],Sort[l0]);
                         if d=Now      then Insert(l,l0) else
                         if d=Sort[l0] then Insert(r0,r)
                                       else WriteLn('Error!')
                       end
             else begin
                    d:=Med3(Now,Sort[l0],Sort[r0]);
                    if d=Now      then Insert(l0,r0) else
                    if d=Sort[l0] then Insert(l,l0)  else
                    if d=Sort[r0] then Insert(r0,r)
                  end
           end
    end;
  begin
    n:=GetN;
    Mid:=(1+n) div 2;
    Sort[1]:=1;
    Sort[2]:=2;
    for Now:=3 to n do
      Insert(0,Now);
    Answer(Sort[Mid])
  end.