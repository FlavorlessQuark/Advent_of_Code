const File = require("fs");

function token_comparator({value: x}, {value: y}) {
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;
}


function get_bots(lines) {
  const bots = {};
  for (let line of lines) {
    const bot_rex = /^(bot \d+) gives low to ((?:bot|output) \d+) and high to ((?:bot|output) \d+)$/;
    const match = bot_rex.exec(line);

    if (!match) continue;

    bots[match[1]] = {low: match[2], high: match[3], pending: []};
    if (match[2].startsWith("output")) bots[match[2]] = {pending: []};
    if (match[3].startsWith("output")) bots[match[3]] = {pending: []};
  }

  return bots;
}

function get_tokens(lines) {
  const tokens = {};
  for (let line of lines) {
    const val_rex = /^value (\d+) goes to ((?:bot|output) \d+)$/;
    const match = val_rex.exec(line);

    if (!match) continue;

    tokens[match[1]] = {value: +match[1], path: [match[2]]};
  }

  return tokens;
}

function execute(bots, tokens) {
  for (let token of Object.values(tokens)) {
    bots[token.path[0]].pending.push(token);
  }

  let stop = false;
  while (!stop) {
    stop = true;

    for (let bot_id of Object.keys(bots)) {
      const bot = bots[bot_id];
      if (!bot_id.startsWith("bot")) continue;
      if (bot.pending.length < 2) continue;

      bot.pending.sort(token_comparator);

      bot.pending[0].path.push(bot.low);
      bots[bot.low].pending.push(bot.pending[0]);

      bot.pending[1].path.push(bot.high);
      bots[bot.high].pending.push(bot.pending[1]);

      bot.pending = [];

      stop = false;
    }
  }
}

const lines = File.readFileSync("input", "utf-8").trim().split("\n");
const bots = get_bots(lines);
const tokens = get_tokens(lines);

execute(bots, tokens);


const part1 = tokens["17"].path.filter(x => tokens["61"].path.includes(x))[0];
const part2 = (
    bots["output 0"].pending[0].value
  * bots["output 1"].pending[0].value
  * bots["output 2"].pending[0].value
  );

console.log("Part One: " + part1);
console.log("Part Two: " + part2);
