const u:array[1..4]of -1..1=(-1,0,0,1);
      v:array[1..4]of -1..1=(0,-1,1,0);

var a,b,c,d,e,f,i,j,m,n,q,head,tail:dword;
    ans:qword;
    jg:boolean;
    map,copy,shit:array[0..40,0..40]of boolean;
    color:array[0..30,0..30]of dword;
    ck:array[0..30,0..30,0..30,0..30]of dword;
    team:array[0..4,0..1000000]of dword;

function onlyoneroad:boolean;

begin
  a:=0;
  for c:=1 to 4 do
    if map[i+u[c],j+v[c]]then inc(a);
  if a=1 then exit(true)else exit(false);
end;

procedure colorit(x,y:dword);
var i:dword;

begin
  copy[x,y]:=false;
  color[x,y]:=b;
  for i:=1 to 4 do
    if copy[x+u[i],y+v[i]]then colorit(x+u[i],y+v[i]);
end;

procedure find(x,y,z:dword);
var i:dword;

begin
  if map[x,y]then
  begin
    if color[x,y]=color[c,d]then
    begin
      ck[x,y,c,d]:=z;
      inc(tail);
      team[0,tail]:=z;
      team[1,tail]:=x;
      team[2,tail]:=y;
      team[3,tail]:=c;
      team[4,tail]:=d;
    end;
    exit;
  end;
  for i:=1 to 4 do
    if shit[x+u[i],y+v[i]]then find(x+u[i],y+v[i],z+1);
end;

begin
  assign(input,'puzzle.in');
  assign(output,'puzzle.out');
  reset(input);
  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(a);
      if a=1 then map[i,j]:=true;
    end;
  shit:=map;
  repeat
    jg:=true;
    for i:=1 to n do
      for j:=1 to n do
        if map[i,j]and onlyoneroad then
        begin
          map[i,j]:=false;
          jg:=false;
        end;
    if jg then break;
    jg:=true;
    for i:=1 to n do
      for j:=n downto 1 do
        if map[i,j]and onlyoneroad then
        begin
          map[i,j]:=false;
          jg:=false;
        end;
    if jg then break;
    jg:=true;
    for i:=n downto 1 do
      for j:=1 to n do
        if map[i,j]and onlyoneroad then
        begin
          map[i,j]:=false;
          jg:=false;
        end;
    if jg then break;
    jg:=true;
    for i:=n downto 1 do
      for j:=n downto 1 do
        if map[i,j]and onlyoneroad then
        begin
          map[i,j]:=false;
          jg:=false;
        end;
  until jg;
  copy:=map;
  for i:=1 to n do
    for j:=1 to m do
      if copy[i,j]then
      begin
        inc(b);
        colorit(i,j);
      end;
  for i:=1 to q do
  begin
    readln(a,b,c,d,e,f);
    if(c=e)and(d=f)then writeln(0)else
    if(a=e)and(b=f)and(abs(c-e)+abs(d-f)=1)then writeln(1)else
    if not(map[c,d]and map[e,f])or(color[c,d]<>color[e,f])then writeln(-1)else
    begin
      head:=1;
      tail:=0;
      find(a,b,0);
      if tail=0 then writeln(-1)else
      begin
        fillchar(ck,sizeof(ck),255);
        repeat
          for j:=1 to 4 do
          begin
            a:=team[1,head]+u[j];
            b:=team[2,head]+v[j];
            if(a=team[3,head])and(b=team[4,head])then
            begin
              c:=team[1,head];
              d:=team[2,head];
            end else
            begin
              c:=team[3,head];
              d:=team[4,head];
            end;
            if map[a,b]and(ck[a,b,c,d]>team[0,head]+1)then
            begin
              ck[a,b,c,d]:=team[0,head]+1;
              inc(tail);
              team[0,tail]:=team[0,head]+1;
              team[1,tail]:=a;
              team[2,tail]:=b;
              team[3,tail]:=c;
              team[4,tail]:=d;
            end;
          end;
          inc(head);
        until head>tail;
        ans:=1<<60;
        for j:=1 to 4 do
        begin
          a:=e+u[j];
          b:=f+v[j];
          if map[a,b]and(ck[a,b,e,f]<ans)then ans:=ck[a,b,e,f];
        end;
        if ans<504651535 then writeln(ans)else writeln(-1);
      end;
    end;
  end;
  close(input);
  close(output);
end.