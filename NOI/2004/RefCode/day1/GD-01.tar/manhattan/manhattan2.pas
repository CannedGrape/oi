{$I-,Q-,R-,S-,V-,X-}
PROGRAM Joshua;
CoNsT
  mxn=100;
VaR
  hsr,vsr,nhs,nvs,shs,svs:array[1..mxn]of byte;
  hp,vp,bx,by:array[1..mxn]of longint;
  x1,y1,x2,y2,my,sk:array[1..mxn]of integer;
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
Function fndtree(o:integer):boolean;
  var
    i:integer;
  begin
    s[o]:=true;
    for i:=1 to n do
      if not t[i] and mp[o,i] then
      begin
        t[i]:=true;
        if (my[i]=0)or fndtree(my[i]) then
        begin
          my[i]:=o;
          fndtree:=true;
          exit;
        end;
      end;
    fndtree:=false;
  end;
Procedure bestmatch(nw:longint);
  var
    i,j,k:integer;
    km:longint;
  begin
    fillchar(my,sizeof(my),0);
    for i:=1 to tx do
    begin
      bx[i]:=2000000000;
      for j:=1 to n do
        if (jn[i,j]>=0)and(jn[i,j]<bx[i]) then
          bx[i]:=jn[i,j];
      if bx[i]=2000000000 then exit;
    end;
    if nw>=min then exit;
    fillchar(by,sizeof(by),0);
    for i:=1 to tx do
      for j:=1 to n do
        mp[i,j]:=bx[i]=jn[i,j];
    for i:=1 to tx do
      repeat
        fillchar(s,sizeof(s),false);
        fillchar(t,sizeof(t),false);
        if fndtree(i) then break;
        km:=2000000000;
        for j:=1 to tx do
          if s[j] then
            for k:=1 to n do
              if not t[k] and(jn[j,k]>=0)and(jn[j,k]-bx[j]-by[k]<km) then
                km:=jn[j,k]-bx[j]-by[k];
        if km=2000000000 then exit;
        if nw>=min then exit;
        for j:=1 to tx do
          if s[j] then
            dec(bx[j],min);
        for j:=1 to n do
          if t[j] then
            inc(by[j],min);
        for j:=1 to tx do
          for k:=1 to n do
            mp[i,j]:=(jn[j,k]>=0)and(jn[j,k]<=bx[j]+by[k]);
      until false;
    for i:=1 to n do
      if my[i]<>0 then
        if x1[sk[my[i]]]<x2[sk[my[i]]] then nvs[i]:=1
        else nvs[i]:=2;
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
            sk[tx]:=i;
            for j:=1 to n do
              jn[tx,j]:=-1;
            for j:=small(y1[i],y2[i]) to large(y1[i],y2[i]) do
              if vsr[j]=b then jn[tx,j]:=0
              else jn[tx,j]:=vp[j];
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
//  assign(output,'manhattan.out');rewrite(output);
  rdfl;
  min:=2000000000;
  search(1,0);
  print;
  close(input);
  close(output);
EnD.
