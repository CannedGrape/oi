var
  n,m,q,i,j,k,z,x,y,r,min:longint;
  zz:boolean;
  dd:array[1..50000] of boolean;
  dl:array[1..50000,0..2] of longint;
  aa:array[1..30000,0..2] of longint;
  //ac:array[1..10000] of longint;
procedure try(v:longint);
var  j:longint;
begin
  if v=y then begin aa[z,0]:=min;
                    exit;
              end;
  for i:=1 to m do
    if dd[i]=false then
    if (dl[i,1]=v) and(dl[i,0]>aa[z,0]) then
      begin
        dd[i]:=true;
        if dl[i,0]<min then
          begin
            j:=min; min:=dl[i,0];
            try(dl[i,2]);
            min:=j;
          end
          else try(dl[i,2]);
        dd[i]:=false;
      end
    else if (dl[i,2]=v)and(dl[i,0]>aa[z,0]) then
      begin
        dd[i]:=true;
        if dl[i,0]<min then
          begin
            j:=min; min:=dl[i,0];
            try(dl[i,1]);
            min:=j;
          end
          else try(dl[i,1]);
        dd[i]:=false;
       end;
end;
begin
  assign(input,'truck.in'); reset(input);
  assign(output,'truck.out'); rewrite(output);
  read(n,m);
  for i:=1 to m do
    begin
      read(dl[i,1],dl[i,2],dl[i,0]);
      if dl[i,1]>dl[i,2] then
        begin
          k:=dl[i,1]; dl[i,1]:=dl[i,2];
          dl[i,2]:=k;
        end;
    end;
  read(q);
  for z:=1 to q do
    begin
      zz:=false;
      read(x,y);
      if x>y then
        begin
          k:=x; x:=y; y:=k;
        end;
      aa[z,1]:=x; aa[z,2]:=y;
      for i:=1 to z-1 do
        if (aa[i,1]=x) and (aa[i,2]=y) then
          begin
            zz:=true;
            writeln(aa[i,0]);
            aa[z,0]:=aa[i,0];
            break;
          end;
      if zz<>true then
        begin
          for i:=1 to m do dd[i]:=false;
          aa[z,0]:=0; try(x);
          if aa[z,0]<>0 then
            begin
              writeln(aa[z,0]); zz:=true;
            end
            else  writeln(-1);
        end;
    end;
  close(input); close(output);
end.

      {if zz<>true then
        begin
          aa[z,0]:=0;  r:=x;
          for i:=1 to m do
            if (dl[i,1]=r) and(dl[i,2]<=y) then
              begin
                if dl[i,0]>aa[z,0] then
                  begin
                  r:=dl[i,2];
                  if dl[i,0]>ans then ans:=dl[i,0];}

  {for i:=1 to q do
    begin
      read(aa[i,1],aa[i,2]);
      if aa[i,1]>aa[i,2] then
        begin
          k:=aa[i,1]; aa[i,1]:=aa[i,2];
          aa[i,2]:=k;
        end;
    end; }
