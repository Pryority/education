# Personal Javascript Website

### Step 1: Install Node.js (if not already installed)

If you don't have Node.js installed, download and install it from Node.js official website.

### Step 2: Create a Package.json File

Navigate to your project folder in the command prompt or terminal and run the following command to initialize a package.json file:

```bash
npm init -y
```

### Step 3: Install Express

Install Express as a dependency for your project:

```bash
npm install express
```

### Step 4: Create an Express Server File (server.js)

Create a file named server.js in your project folder and add the following code:

```javascript
const express = require("express");
const path = require("path");

const app = express();
const port = process.env.PORT || 3000;

// Serve static files (HTML, CSS, JS) from the 'public' folder
app.use(express.static(path.join(__dirname, "public")));

// Define a route for the home page
app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "public", "index.html"));
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
```

### Step 5: Organize Your Project Folder

Make sure your project folder structure looks like this:

```markdown
- your-project-folder
  - public
    - index.html
    - style.css
    - script.js
  - server.js
  - package.json
  - (other files and folders)
```

### Step 6: Start the Express Server

Run the following command in the command prompt or terminal to start the server:

```bash
node server.js
```

### Step 7: Open Your Website in a Browser

Open your web browser and go to http://localhost:3000. You should be able to view your personal website served by the Express.js server.
