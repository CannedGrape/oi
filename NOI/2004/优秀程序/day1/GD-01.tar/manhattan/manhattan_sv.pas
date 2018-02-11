{$I-,Q-,R-,S-,V-,X-}
PROGRAM Joshua;
CoNsT
  mxn=100;
VaR
  hsr,vsr,nhs,nvs,shs,svs:array[1..mxn]of byte;
  hp,vp,bx,by:array[1..mxn]of longint;
  x1,y1,x2,y2,my,vs,vt,vn:array[1..mxn]of integer;
  jn:array[1..mxn,1..mxn]of longint;
  mp:array[1..mxn,1..mxn]of boolean;
  s,t:array[1..mxn]of boolean;
  m,n,p,tx:integer;
  min:longint;
Procedure rdfl;
  var
    i,k,a,b,c,d:integer;
    ch:char;
  begin
    readln(m,n);
    for i:=1 to m do
    begin
      read(ch);
      if ch='E' then hsr[i]:=1
      else hsr[i]:=2;
    end;
    readln;
    for i:=1 to n do
    begin
      read(ch);
      if ch='S' then vsr[i]:=1
      else vsr[i]:=2;
    end;
    readln;
    for i:=1 to m do
      read(hp[i]);
    for i:=1 to n do
      read(vp[i]);
    p:=0;
    read(k);
    for i:=1 to k do
    begin
      read(a,b,c,d);
      if (a<>c)or(b<>d) then
      begin
        inc(p);
        x1[p]:=a;
        y1[p]:=b;
        x2[p]:=c;
        y2[p]:=d;
      end;
    end;
  end;
Function small(a,b:integer):integer;
  begin
    if a<b then small:=a else small:=b;
  end;
Function large(a,b:integer):integer;
  begin
    if a>b then large:=a else large:=b;
  end;
Procedure greedy(nw:longint);
  var
    i,j,k,o:longint;
    brk,mk:boolean;
  begin
    repeat
      brk:=true;
      for i:=1 to tx do
      begin
        mk:=true;
        for j:=vs[i] to vt[i] do
          if (nvs[j]=vn[i])or(nvs[j]=0)and(vsr[j]=vn[i]) then
          begin
            mk:=false;
            break;
          end;
        if mk then
        begin
          k:=2000000000;
          for j:=vs[i] to vt[i] do
            if (nvs[j]=0)and(vp[j]<k) then
            begin
              k:=vp[j];
              o:=j;
            end;
          if k=2000000000 then exit;
          nvs[o]:=vn[i];
          brk:=false;
        end;
      end;
    until brk;
    for i:=1 to n do
      if nvs[i]=0 then nvs[i]:=vsr[i]
      else if nvs[i]<>vsr[i] then inc(nw,vp[i]);
    if nw<min then
    begin
      min:=nw;
      shs:=nhs;
      svs:=nvs;
    end;
  end;
Procedure check(nw:longint);
  var
    i,j,a,b:integer;
    flg:boolean;
  begin
    fillchar(nvs,sizeof(nvs),0);
    tx:=0;
    for i:=1 to p do
      if y1[i]=y2[i] then
      begin
        if x1[i]<x2[i] then
          if nvs[y1[i]]=2 then exit
          else nvs[y1[i]]:=1
        else
          if nvs[y1[i]]=1 then exit
          else nvs[y1[i]]:=2;
      end else
      begin
        if y1[i]<y2[i] then a:=1 else a:=2;
        if x1[i]<>x2[i] then
        begin
          if x1[i]<x2[i] then b:=1 else b:=2;
          if (nhs[x1[i]]=a)and(nhs[x2[i]]=a) then
          begin
            inc(tx);
            vs[tx]:=small(y1[i],y2[i]);
            vt[tx]:=large(y1[i],y2[i]);
            vn[tx]:=b;
          end else
          begin
            if nhs[x1[i]]<>a then
              if nvs[y1[i]]=3-b then exit
              else nvs[y1[i]]:=b;
            if nhs[x2[i]]<>a then
              if nvs[y2[i]]=3-b then exit
              else nvs[y2[i]]:=b;
            if (nhs[x1[i]]<>a)and(nhs[x2[i]]<>a) then
            begin
              flg:=true;
              for j:=small(x1[i],x2[i]) to large(x1[i],x2[i]) do
                if nhs[j]=a then
                  flg:=false;
              if flg then exit;
            end;
          end;
        end else if nhs[x1[i]]<>a then exit;
      end;
    greedy(nw);
  end;
Procedure search(o:integer;nw:longint);
  begin
    if nw>=min then exit;
    if o>m then
    begin
      check(nw);
      exit;
    end;
    nhs[o]:=hsr[o];
    search(o+1,nw);
    nhs[o]:=3-nhs[o];
    search(o+1,nw+hp[o]);
  end;
Procedure print;
  var
    i:integer;
  begin
    if min<2000000000 then
    begin
      writeln('possible');
      writeln(min);
      for i:=1 to m do
        if shs[i]=1 then write('E')
        else write('W');
      writeln;
      for i:=1 to n do
        if svs[i]=1 then write('S')
        else write('N');
      writeln;
    end else writeln('impossible');
  end;
BeGiN
  assign(input,'manhattan.in'); reset(input);
//  assign(output,'manhattan.out');rewrite(output);
  rdfl;
  min:=2000000000;
  search(1,0);
  print;
  close(input);
  close(output);
EnD.
        if (nhs[x1[i]]<>a)and(nhs[x2[i]]<>a) then
            begin
              flg:=true;
              for j:=small(x1[i],x2[i]) to large(x1[i],x2[i]) do
                if nhs[j]=a then
                  flg:=false;
              if flg then exit;
            end;
          end;
        end else if nhs[x1[i]]<>a then exit;
      end;
    for j:=1 to n do
      if nvs[j]<>0 then
        for i:=1 to tx do
          if x1[sk[i]]<x2[sk[i]] then
            if nvs[j]=1 then jn[i,j]:=0
            else jn[i,j]:=-1
          else
            if nvs[j]=2 then jn[i,j]:=0
            else jn[i,j]:=-1;
    bestmatch(nw);
  end;
Procedure search(o:integer;nw:longint);
  begin
    if nw>=min then exit;
    if o>m then
    begin
      check(nw);
      exit;
    end;
    nhs[o]:=hsr[o];
    search(o+1,nw);
    nhs[o]:=3-nhs[o];
    search(o+1,nw+hp[o]);
  end;
Procedure print;
  var
    i:integer;
  begin
    if min<2000000000 then
    begin
      writeln('possible');
      writeln(min);
      for i:=1 to m do
        if shs[i]=1 then write('E')
        else write('W');
      writeln;
      for i:=1 to n do
        if svs[i]=1 then write('S')
        else write('N');
      writeln;
    end else writeln('impossible');
  end;
BeGiN
  assign(input,'manhattan.in'); reset(input);
  assign(output,'manhattan.out');rewrite(output);
  rdfl;
  min:=2000000000;
  search(1,0);
  print;
  close(input);
  close(output);
EnD.
