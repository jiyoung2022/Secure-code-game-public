const express = require('express') 
const app = express()

app.get('/level-2', (req, res) => {
  var number = req.query.number;
  console.log(number);
  if (number.length < 4) {
    if (number > 10000) {
      res.send('Success!!');
    } else {
      res.send('Failed!!');
    }
  } else {
    res.send('Failed!!');
  }
})

const PORT = 8000
const server = app.listen(PORT, () => {
  console.log(`Listening on port ${PORT}`)
})

module.exports = server
